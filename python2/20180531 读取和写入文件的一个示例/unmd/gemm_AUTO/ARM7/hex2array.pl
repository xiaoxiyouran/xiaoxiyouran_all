#! /usr/bin/perl

@ARGV != 2 && die "2 arguments required\n";

$inputfile = shift @ARGV;
$outputfile = shift @ARGV;

open IN, "<$inputfile" or die "can't open input file\n";
open OUT, ">$outputfile";

$i=0;
@line = <IN>;
#chomp(@line);

foreach $old_line (@line) {
   $old_line =~s/\r\n//g;
   print OUT "0x";
   print OUT "$old_line";
   print OUT ",";
   $i++;
   if ($i%8==0) {
    print OUT "\n";
   } else {
   }
}

close IN;
close OUT;
