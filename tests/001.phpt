--TEST--
Output SAMPLE\SAMPLE_INT constant and expect 42
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$greeting = new Sample\Greeting("Universe");
$greeting->hello();
?>
--EXPECT--
Hello Universe!