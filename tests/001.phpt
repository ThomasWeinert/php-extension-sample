--TEST--
Output SAMPLE\SAMPLE_INT constant and expect 42
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$greeting = new Sample\Greeting();
$greeting->hello();
?>
--EXPECT--
Hello World!