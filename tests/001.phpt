--TEST--
Call method "do" on provided object argument.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Hello {
    public function do($name) {
        printf("Hello %s!\n", $name);
    }
}

\sample\greet(new Hello("World"));
?>
--EXPECT--
Hello World!
