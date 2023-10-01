--TEST--
Call function with optional argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \Sample\multiply(21), "\n", \Sample\multiply(21, 2);
?>
--EXPECT--
21
42
