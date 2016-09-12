--TEST--
Call function with optional argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \sample\multiply(21), "\n", \sample\multiply(21, 2);
?>
--EXPECT--
21
42
