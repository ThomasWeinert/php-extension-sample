--TEST--
Call method "do" repeatedly on provided object argument.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Target {
    public function do($number) {
        printf("[%d]\n", $number);
    }
}

\sample\countdown(new Target());
?>
--EXPECT--
[10]
[9]
[8]
[7]
[6]
[5]
[4]
[3]
[2]
[1]
