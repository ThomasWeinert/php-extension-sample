--TEST--
Call method "do" five times on provided object argument.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Target {
    public function do($number) {
        printf("[%d]\n", $number);
    }
}

\sample\countdown(new Target(), 5);
?>
--EXPECT--
[5]
[4]
[3]
[2]
[1]
