--TEST--
Return an stdClass instance with some properties set.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
var_dump(\Sample\answer());
?>
--EXPECT--
object(stdClass)#1 (1) {
  ["greeting"]=>
  string(12) "Hello World!"
}
