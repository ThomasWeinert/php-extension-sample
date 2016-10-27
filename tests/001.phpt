--TEST--
Implement Sample\SampleInterface into an object and validate
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class SampleClass implements Sample\SampleInterface {
  public function sampleMethod() {
    echo ($this instanceof Sample\SampleInterface) ? 'Implemented Interface' : 'FAIL';
  }
}
(new SampleClass())->sampleMethod();

?>
--EXPECT--
Implemented Interface