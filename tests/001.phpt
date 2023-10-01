--TEST--
Call function with string argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
\Sample\hello('Universe');
?>
--EXPECT--
Hello Universe!
