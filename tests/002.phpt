--TEST--
Return an object after calling its constructor and call a property.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
$greeting = \Sample\getGreeting();
echo $greeting->name;
?>
--EXPECT--
Universe
