--TEST--
Call function with string argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
echo \Sample\hello('World', 'Universe');
?>
--EXPECT--
Hello World!
Hello Universe!
