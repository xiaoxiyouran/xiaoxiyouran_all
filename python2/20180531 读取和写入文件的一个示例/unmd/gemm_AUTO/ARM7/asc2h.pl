#!/usr/bin/perl -w

die "Usage: perl $0  <infile> <outfile> " unless (@ARGV==2);

my $INPUT_NAME = $ARGV[0];
my $OUT_NAME = $ARGV[1];

open INFILE, $INPUT_NAME or die "$!";
open OUTFILE, '>'.$OUT_NAME or die "$!";

while(chomp($get_line = <INFILE>))
{

   my $rd_data = hex($get_line); 
   printf OUTFILE"0x%08X,\n",$rd_data; 
}

close INFILE;
close OUTFILE; 
