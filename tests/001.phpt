--TEST--
Output a greeting for the name provided as the constructor argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$greeting = new Sample\Greeting("Universe");
$greeting->hello();
?>
--EXPECT--
Hello Universe!