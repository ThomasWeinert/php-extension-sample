--TEST--
Return an object after calling its constructor.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
$greeting = \sample\getGreeting();
$greeting->hello();
?>
--EXPECT--
Hello Universe!
