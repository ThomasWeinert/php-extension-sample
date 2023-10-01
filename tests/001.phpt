--TEST--
Extend abstract Sample\SampleClass and validate
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class SampleClass extends Sample\SampleClass {
  public function sampleMethod(): void {
    echo ($this instanceof Sample\SampleClass) ? 'SUCCESS' : 'FAIL';
  }
}
(new SampleClass())->sampleMethod();

?>
--EXPECT--
SUCCESS