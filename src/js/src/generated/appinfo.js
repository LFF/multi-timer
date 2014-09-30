/*

Multi Timer v3.0

http://matthewtole.com/pebble/multi-timer/

----------------------

The MIT License (MIT)

Copyright © 2013 - 2014 Matthew Tole

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

--------------------

src/js/src/generated/appinfo.js

*/

/* exported AppInfo */

var AppInfo = {
  "uuid": "0db6a55e-b32a-4b03-b037-95637bf306ff",
  "shortName": "Multi Timer",
  "longName": "Multi Timer",
  "companyName": "Matthew Tole",
  "versionCode": 1,
  "versionLabel": "3.0",
  "watchapp": {
    "watchface": false
  },
  "appKeys": {
    "group": 0,
    "operation": 1,
    "data": 2
  },
  "capabilities": [ "configurable" ],
  "config": {
    "settingsUrl": "http://192.168.0.8:6006/multi-timer/config/",
    "socketUrl": "http://192.168.0.8:6006/multi-timer",
    "keen": {
      "projectId": "53a84295bcb79c58c7000002",
      "writeKey": "f91165f494c5bff28908caf75bf0a07ded19fe01ec813985c3ad466fe8e7799879e3a5246b0e504ea97fc80b10d39faeda96e1a5811af406a203721ce92d8a97c9f1d4bebf53b80a60b57f78784fac3880b888062084a3a3070650f650777ed3a1048d941ac76f3b6ad739e32931bf6c"
    }
  },
  "delimiters": {
    "inner": "`",
    "outer": "~"
  },
  "debug": true,
  "resources": {
    "media": [
      {
        "menuIcon": true,
        "type": "png",
        "name": "MENU_ICON",
        "file": "images/menu.png"
      }
    ]
  }
};