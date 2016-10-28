--TEST--
Output a greeting using Sample\Greeting::hello()
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$greeting = new Sample\Greeting();
$greeting->hello();
?>
--EXPECT--
Hello World!