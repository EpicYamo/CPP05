# CPP Module 05

Repetition and exceptions: grades that throw, forms that must be signed before they run, and a factory that builds them by name.

> Part of the **42 school curriculum**. Built by **Arda Aycan**.

## Exercises

| Exercise | Binary | What it demonstrates |
| --- | --- | --- |
| `ex00` | `bureaucrats_and_their_exceptions` | `Bureaucrat` with a grade in 1–150; constructing or promoting outside the range throws a nested exception type. |
| `ex01` | `form_up_maggots` | `Form` with a sign grade and an execute grade; `beSigned` throws when the bureaucrat's grade is too low. |
| `ex02` | `this_not_that` | An abstract `AForm` and three concrete forms: shrubbery creation, robotomy request and presidential pardon. |
| `ex03` | `beats_coffee_making` | `Intern` maps a form name to a freshly allocated form, returning `NULL` for unknown names. |

## Build and run

Every exercise has its own Makefile and produces its own binary:

```bash
make -C ex00
./ex00/bureaucrats_and_their_exceptions
```

`make fclean -C <exercise>` removes the binary again.

## Notes

- C++98, `-Wall -Wextra -Werror`.
- Exceptions are used for control flow, not `errno` or return codes.

## Author

**Arda Aycan** ([@EpicYamo](https://github.com/EpicYamo)).
