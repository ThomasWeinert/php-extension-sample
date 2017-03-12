--TEST--
Catch a thrown SPL exception (\LogiException).
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
try {
  echo \sample\trigger();
} catch (\LogicException $e) {
  echo $e->getCode(), ' -> ', $e->getMessage();
}
?>
--EXPECT--
42 -> Sample Exception Message
