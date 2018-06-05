/*
 *
 * Copyright (c) 2006, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * -Redistributions of source code must retain the above copyright
 * notice, this  list of conditions and the following disclaimer.
 *
 * -Redistribution in binary form must reproduct the above copyright
 * notice, this list of conditions and the following disclaimer in
 * the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Oracle nor the names of
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * This software is provided "AS IS," without a warranty of any
 * kind. ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND
 * WARRANTIES, INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY
 * EXCLUDED. SUN AND ITS LICENSORS SHALL NOT BE LIABLE FOR ANY
 * DAMAGES OR LIABILITIES  SUFFERED BY LICENSEE AS A RESULT OF  OR
 * RELATING TO USE, MODIFICATION OR DISTRIBUTION OF THE SOFTWARE OR
 * ITS DERIVATIVES. IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE
 * FOR ANY LOST REVENUE, PROFIT OR DATA, OR FOR DIRECT, INDIRECT,
 * SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER
 * CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING OUT OF
 * THE USE OF OR INABILITY TO USE SOFTWARE, EVEN IF SUN HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 * You acknowledge that Software is not designed, licensed or
 * intended for use in the design, construction, operation or
 * maintenance of any nuclear facility.
 */

import org.ietf.jgss.*;
import java.net.Socket;
import java.io.IOException;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.security.*;
import javax.security.auth.login.LoginException;

/**
 * A sample client application that uses JGSS to do mutual authentication
 * with a server using Kerberos as the underlying mechanism. It then
 * exchanges data securely with the server.
 *
 * Every message sent to the server includes a 4-byte application-level
 * header that contains the big-endian integer value for the number
 * of bytes that will follow as part of the JGSS token.
 *
 * The protocol is:
 *    1.  Context establishment loop:
 *         a. client sends init sec context token to server
 *         b. server sends accept sec context token to client
 *         ....
 *    2. client sends a wrapped token to the server.
 *    3. server sends a wrapped token back to the client for the application
 *
 * Start GssServer first before starting GssClient.
 *
 * Usage:  java <options> GssClient <service> <serverName>
 *
 * Example: java -Djava.security.auth.login.config=jaas-krb5.conf \
 *               GssClient host machine.imc.org
 *
 * Add -Djava.security.krb5.conf=krb5.conf to specify application-specific
 * Kerberos configuration (different from operating system's Kerberos
 * configuration).
 */

public class GssClient {
    private static final int PORT = 4567;
    private static final boolean verbose = false;

    public static void main(String[] args) throws Exception {

        // Obtain the command-line arguments and parse the server's principal

        if (args.length < 2) {
            System.err.println(
                "Usage: java <options> GssClient <service> <serverName>");
            System.exit(-1);
        }

        String serverPrinc = args[0] + "@" + args[1];

        PrivilegedExceptionAction action =
            new GssClientAction(serverPrinc, args[1], PORT);

        Jaas.loginAndAction("client", action);
    }

    static class GssClientAction implements PrivilegedExceptionAction {
        private String serverPrinc;
        private String hostName;
        private int port;

        GssClientAction(String serverPrinc, String hostName, int port) {
            this.serverPrinc = serverPrinc;
            this.hostName = hostName;
            this.port = port;
        }

        public Object run() throws Exception {
            Socket socket = new Socket(hostName, port);
            DataInputStream inStream =
                new DataInputStream(socket.getInputStream());
            DataOutputStream outStream =
                new DataOutputStream(socket.getOutputStream());

            System.out.println("Connected to address " +
                socket.getInetAddress());

            /*
             * This Oid is used to represent the Kerberos version 5 GSS-API
             * mechanism. It is defined in RFC 1964. We will use this Oid
             * whenever we need to indicate to the GSS-API that it must
             * use Kerberos for some purpose.
             */
            Oid krb5Oid = new Oid("1.2.840.113554.1.2.2");

            GSSManager manager = GSSManager.getInstance();

            /*
             * Create a GSSName out of the server's name.
             */
            GSSName serverName = manager.createName(serverPrinc,
                GSSName.NT_HOSTBASED_SERVICE);

            /*
             * Create a GSSContext for mutual authentication with the
             * server.
             *    - serverName is the GSSName that represents the server.
             *    - krb5Oid is the Oid that represents the mechanism to
             *      use. The client chooses the mechanism to use.
             *    - null is passed in for client credentials
             *    - DEFAULT_LIFETIME lets the mechanism decide how long the
             *      context can remain valid.
             * Note: Passing in null for the credentials asks GSS-API to
             * use the default credentials. This means that the mechanism
             * will look among the credentials stored in the current Subject
             * to find the right kind of credentials that it needs.
             */
            GSSContext context = manager.createContext(serverName,
                krb5Oid,
                null,
                GSSContext.DEFAULT_LIFETIME);

            // Set the desired optional features on the context. The client
            // chooses these options.

            context.requestMutualAuth(true);  // Mutual authentication
            context.requestConf(true);  // Will use confidentiality later
            context.requestInteg(true); // Will use integrity later

            // Do the context eastablishment loop

            byte[] token = new byte[0];

            while (!context.isEstablished()) {

                // token is ignored on the first call
                token = context.initSecContext(token, 0, token.length);

                // Send a token to the server if one was generated by
                // initSecContext
                if (token != null) {
                    if (verbose) {
                        System.out.println("Will send token of size " +
                            token.length + " from initSecContext.");
                        System.out.println("writing token = " +
                            getHexBytes(token));
                    }

                    outStream.writeInt(token.length);
                    outStream.write(token);
                    outStream.flush();
                }

                // If the client is done with context establishment
                // then there will be no more tokens to read in this loop
                if (!context.isEstablished()) {
                    token = new byte[inStream.readInt()];
                    if (verbose) {
                        System.out.println("reading token = " +
                            getHexBytes(token));
                        System.out.println("Will read input token of size " +
                            token.length + " for processing by initSecContext");
                    }
                    inStream.readFully(token);
                }
            }

            System.out.println("Context Established! ");
            System.out.println("Client principal is " + context.getSrcName());
            System.out.println("Server principal is " + context.getTargName());

            /*
             * If mutual authentication did not take place, then only the
             * client was authenticated to the server. Otherwise, both
             * client and server were authenticated to each other.
             */
            if (context.getMutualAuthState())
                System.out.println("Mutual authentication took place!");

            byte[] messageBytes = "Hello There!".getBytes("UTF-8");

            /*
             * The first MessageProp argument is 0 to request
             * the default Quality-of-Protection.
             * The second argument is true to request
             * privacy (encryption of the message).
             */
            MessageProp prop =  new MessageProp(0, true);

            /*
             * Encrypt the data and send it across. Integrity protection
             * is always applied, irrespective of confidentiality
             * (i.e., encryption).
             * You can use the same token (byte array) as that used when
             * establishing the context.
             */

            System.out.println("Sending message: " +
                new String(messageBytes, "UTF-8"));
            token = context.wrap(messageBytes, 0, messageBytes.length, prop);
            outStream.writeInt(token.length);
            outStream.write(token);
            outStream.flush();

            /*
             * Now we will allow the server to decrypt the message,
             * append a time/date on it, and send then it back.
             */

            token = new byte[inStream.readInt()];
            System.out.println("Will read token of size " + token.length);
            inStream.readFully(token);
            byte[] replyBytes = context.unwrap(token, 0, token.length, prop);

            System.out.println("Received message: " +
                new String(replyBytes, "UTF-8"));

            System.out.println("Done.");
            context.dispose();
            socket.close();

            return null;
        }
    }

    private static final String getHexBytes(byte[] bytes, int pos, int len) {

        StringBuffer sb = new StringBuffer();
        for (int i = pos; i < (pos+len); i++) {

            int b1 = (bytes[i]>>4) & 0x0f;
            int b2 = bytes[i] & 0x0f;

            sb.append(Integer.toHexString(b1));
            sb.append(Integer.toHexString(b2));
            sb.append(' ');
        }
        return sb.toString();
    }

    private static final String getHexBytes(byte[] bytes) {
        return getHexBytes(bytes, 0, bytes.length);
    }
}
