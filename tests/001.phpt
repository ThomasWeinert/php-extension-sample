--TEST--
var_dump() an array returned by a function
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
var_dump(\Sample\getGreetingParts());
?>
--EXPECT--
array(2) {
  ["greeting"]=>
  string(9) "Hello %s!"
  ["who"]=>
  string(5) "World"
}
