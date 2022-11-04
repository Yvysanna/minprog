# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

The longest word in the dictionary; in this case also the limit to the length of words allowed for this code

## According to its man page, what does `getrusage` do?

it returns the resource usage measures, dependently from its `who` argument

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

We pass `before` and `after`, so that the computer can then tell us how much time it takes to go through this part of the function

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The for loop runs for int c taken from the file, as long as it's not the end of the file and updates it with a character taken from the file.
Following, it checks if c is an alphabetical character or an apostrophe, if a word is following the apostrophe. Then it creates a copy of the word by
adding every single letter to word[index] until the word has come to an end.
In the following else if statement it checks if the word contains a digit and if so, skips it.
Afterwards, it checks if the end of a word may have come and in case it did, prepare the counter/ the for loop for the following word.
Then it checks for the time it takes to check the word spelling, spell checks the word and keeps the time once the word has been spell-checked.
If the word is missspelled, it will be added to the missspel counter.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

When checking the whole word, it becomes more complicated to check if any of those characters in the word is missspelled. Therefore it is better to check
letter by letter if the character's order accords to characters from the dictionary or not. It also sees a word as a whole but does for example not recognize
non-alphabetic characters distinct from alphabetic characters, thus it would also accept strings as words that gramatically seen are not words.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Since constant char is a mutable pointer to an immutable character of a string, you cannot change the contents of the character. In this case, this is a
safety choice through which when running into mistakes, one cannot accidentally change the characters of the word to be spell checked.