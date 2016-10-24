--TEST--
Call function with string argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
echo \sample\hello('World', 'Universe', 42);
?>
--EXPECT--
Hello World!
Hello Universe!
Hello 42!
