# README

unixhexdump is a linux shell tool that converts a string with the format **deadbeef** to the format **\xde\xad\xbe\xef**

## Introduction

This tool was written, when I was looking for a way to send a hash calculated by *md5sum* with the *echo* command to a *tty* device. Because the *echo* command needed the above mentioned format to not interpret the data as ASCII characters I had to write this tool. I finally end up with following commands:

``` shell
echo "deadbeef" | xargs unixhexdump | echo -ne > /dev/ttyX
```
