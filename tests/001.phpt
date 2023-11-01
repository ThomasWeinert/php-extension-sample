--TEST--
Call method "do" on provided object argument.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Hello {
    public function do() {
        printf("Hello World!\n");
    }
}

\sample\greet(new Hello());
?>
--EXPECT--
Hello World!
