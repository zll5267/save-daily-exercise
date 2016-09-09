#!/usr/bin/perl

use Cwd;

$NumOfDouble = 10e2;
print $NumOfDouble;

print "\n";

$MyChars = 'Hello' . ' ' . 'World';
print $MyChars,"\n";

$MyChars = $MyChars * 4;
print $MyChars;print"\n";

$NumOfDouble = $NumOfDouble * 4;
print $NumOfDouble, "\n";

$MyString = "My chars is: $MyChars"."\n";

print $MyString, "\n";

if ("ab" lt "bc") {
    print "ab > bc", "\n";
}

if (5 > 2) {
    print "5 > 2", "\n";
}

if ('0') {
    print " '0' is true", "\n";
} else {
    print " '0' is false", "\n";
}

$text = "Hello world\n";
print $text;
chomp($text);
print $text;

print " input the text:";
$inputFromUser = <STDIN>;#remove the end-of-line

if (defined($inputFromUser)) { #???
    print "input is:$inputFromUser", "\n";
} else {
    print "input is null\n";
}

#print " input the text:";
#while(defined($inputFromUser = <STDIN>)) {
#    print "input is: $inputFromUser", "\n";
#}

$count = 0;
while ($count < 3) {
    print "now count is $count", "\n";
    $count++;
}

#array
$array[0] = 1;
$array[2] = "hh";
print @array, "\n";

@array = qw( this is a test );
foreach $key (@array) {
    print $key, "\n";
}

@array = 1..5;
foreach $key (@array) {
    print $key, "\n";
}

print (pop @array), "\n";
print (pop @array), "\n";
print (pop @array), "\n";
print "\n";
push (@array, 11..15);

foreach $key (@array) {
    print $key, "\n";
}

print (shift @array), "\n";
print (shift @array), "\n";
print (shift @array), "\n";
print "\n";
foreach $key (@array) {
    print $key, "\n";
}

sub marine {
    print @_[0], "\n";
    my($para2) = @_[1];
    print $para2, "\n";
}
&marine("ni", "hao");

marine("hello", "world");

print @ARGV, "\n";


#die "exit sssssssssss $!"

%testHash = ('a' => 1, 'b' => 2, 'c' => 3);

print %testHash, "\n";

while (($k, $v) = each %testHash) {
    print "$k => $v", "\n";
}


print "current dir:", &getcwd, "\n";
my @allfiles = glob "*";
print "all files in current dir:", @allfiles, "\n";


$pointerOfARGV = \@ARGV;

print "pointerOfARGV is: $pointerOfARGV", "\n";


$testString = "zhang \"leliang)\" test)";
#$testString = "zhang leliang) test)";

$firstIndexOfQuota = -1;
$secondIndexOfQuota = 0;
$firstIndexOfBra = 0;

while ($firstIndexOfQuota < $firstIndexOfBra) {
    print "firstIndexOfQuota: $firstIndexOfQuota \n";
    print "firstIndexOfBra: $firstIndexOfBra \n";
    print "secondIndexOfQuota: $secondIndexOfQuota \n";
    if ($firstIndexOfQuota > 0) {
        $secondIndexOfQuota = index($testString, "\"", $firstIndexOfQuota + 1);
    }
    $firstIndexOfQuota = index($testString, "\"", $secondIndexOfQuota +1);
    $firstIndexOfBra = index($testString, ")", $secondIndexOfQuota + 1);
    if (-1 == $firstIndexOfQuota) {
        last;
    }
}
    print "firstIndexOfQuota: $firstIndexOfQuota \n";
    print "firstIndexOfBra: $firstIndexOfBra \n";
    print "secondIndexOfQuota: $secondIndexOfQuota \n";
$resultString = substr($testString, 0, $firstIndexOfBra + 1);
print "$resultString", "\n";
