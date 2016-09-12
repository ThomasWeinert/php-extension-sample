--TEST--
Capture an exception
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
try {
  \sample\triggerException();
} catch (\Sample\ExceptionName $e) {
  echo $e->getCode(), ' -> ', $e->getMessage();
}
?>
--EXPECT--
42 -> Sample Exception Message
