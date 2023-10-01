--TEST--
Output the name property provided in the constructor argument
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$greeting = new Sample\Greeting("Universe");
echo $greeting->name;
?>
--EXPECT--
Universe