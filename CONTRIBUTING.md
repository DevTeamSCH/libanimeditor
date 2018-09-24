# How to contribute

## Creating issues (bug reports, enhancement suggestions etc)
Bug reports should be clear and precise. They should describe the problem in as much detail as possible, so they will easier to reproduce and fix. You should follow these general guidelines in an issue:

* Avoid duplicate issues. Before creating a new one, check if there is a similar issue open.
* Come up with a short and concise title, that describes the problem clearly.
* Write a description of the problem or suggestion. Should contain every important detail (especially the steps required to reproduce the bug, if it's a bug report), but try to keep it clear and on topic.
* Issues are easier to read if they are formatted. You can use [GitHub flavored Markdown](https://guides.github.com/features/mastering-markdown/), which has a simple syntax but provides many possibilities to format text.

## Contributing code

### Using branches
Whenever you start working on a new feature, you should create a new branch for it. Branches should have a short name that describes the feature. When a feature is ready, create a pull request for it to get into the master branch.

### C++ coding style
1. Use **tabs** instead of spaces.
2. Put opening **braces** last on the line, and the closing braces first of the line. E.g.:
    ```
    if (something) {
    	do_something();
    }
    ```
    ```
    class Foo {
    	...
    };
    ```
    However there is an exception, namely **functions**: you should put both braces on separate lines when defining a function. E.g.:
    ```
    void foo()
    {
    	...
    }
    ```
3. Put a **space after keywords**, except after keywords like *alignof, typeof, sizeof etc.* as they are used as functions anyways. E.g.:
    ```
    while (x > 0) {
    	...
    }
    ```
    But no space here:
    ```
    typeof(x)
    ```
4. When using **switch cases** the cases should be on the same indentation level as the switch case itself. E.g.:
    ```
    switch (something) {
    case SMTH_1:
    	...
    	break;
    case SMTH_2:
    	...
    	break;
    }
    ```
5. When **naming** *classes, functions and variables* use **camel-case**. Start classes' name with an *uppercase* letter, and variables' and functions' with a *lowercase*. E.g.:
    ```
    class MySampleClass {
    	void mySampleFunction()
    	{
    		int mySampleVariable;
    	}
    };
    ```
6. When **commenting** use the following examples as a guideline:
    ```
    // One line comment, and there is a space after the second forward slash.
    ```
    ```
    /*
     * Multiple line comment.
     * Notice the first and last line is empty,
     * and there is a space after the asterisks,
     * and also they line up below each other.
     */
    ```
7. And lastly, the **lines** should be maximum **80 columns long**.

### Commit messages
Commit messages should help others understand the reasons and the contents of your change. You should write a short message in imperative.
