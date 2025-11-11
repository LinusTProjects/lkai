# Contributing

## Before You Submit Anything

1. **Read the code.** All of it. If you can't understand it, you shouldn't be modifying it.

2. **Run the tests.** If you don't know how, figure it out.

3. **Check your ego at the door.** Your code will be criticized. This isn't personal.

## Code Style

- Follow kernel coding style (Documentation/process/coding-style.rst in the kernel tree)
- Tabs, not spaces. 8 characters. This isn't negotiable.
- Keep lines under 80 characters when possible
- No trailing whitespace. Ever.
- Comments explain *why*, not *what*

## Commit Messages

```
subsystem: short description (50 chars max)

Longer explanation of what this change does and why it's needed.
Wrap at 72 characters. Be specific.

Signed-off-by: Your Name <your@email.com>
```

Bad commit messages:
- "fix bug"
- "update code"
- "WIP"
- anything with emojis

## Pull Requests

1. One logical change per PR
2. Rebase on main before submitting
3. Make sure it compiles. With warnings enabled. With -Werror.
4. Include test results
5. Explain what you changed and why

## What Not To Do

- Don't "clean up" code that works
- Don't add abstraction for its own sake
- Don't add dependencies we don't need
- Don't submit half-finished work
- Don't argue about style after I've made a decision

## Questions?

If you've read everything and still have questions, open an issue. Make sure the question isn't answered in existing documentation first.

---

*If this seems harsh, consider that every line of code in here runs in kernel space. Bugs don't just crash your app - they can crash your system or worse. Standards exist for a reason.*
