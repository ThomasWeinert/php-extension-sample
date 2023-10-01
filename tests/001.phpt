--TEST--
getValue() should return alternating values of 21 and 42
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
for ($i = 0; $i < 4; $i++) {
  echo \Sample\getValue();
}
?>
--EXPECT--
Current value: 21
Current value: 42
Current value: 21
Current value: 42
