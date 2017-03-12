--TEST--
Create and use sample resource
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
$r = sample\createResource();
sample\useResource($r);
?>
--EXPECT--
Number: 42
