--TEST--
Call function with string argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \sample\output(42), "\n";
echo \sample\output(FALSE), "\n";
echo \sample\output("Hello World"), "\n";
?>
--EXPECT--
Integer: 42
Boolean: FALSE
String: Hello World
