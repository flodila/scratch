# JSON String Unescaper in C

I've got some issues with the
[Kubernetes filter in fluent-bit](https://github.com/fluent/fluent-bit/tree/master/plugins/filter_kubernetes).
And I believe that its `unescape_string` function is the problem.

Now I want to fix it but really don't have any experience in programming C ...

This is my first attempt to unescape a
[JSON string](http://www.ietf.org/rfc/rfc4627.txt). It may even work :-)
