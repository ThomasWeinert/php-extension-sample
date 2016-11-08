--TEST--
var_dump() an array returned by a function
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
var_dump(\sample\getGreetings(['World', "Universe", 42]));
?>
--EXPECT--
array(3) {
  [0]=>
  string(12) "Hello World!"
  [1]=>
  string(15) "Hello Universe!"
  [2]=>
  string(9) "Hello 42!"
}
