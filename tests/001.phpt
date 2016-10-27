--TEST--
Output Sample\SampleClass::ANSWER constant and expect 42
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
echo Sample\SampleClass::ANSWER;
?>
--EXPECT--
42