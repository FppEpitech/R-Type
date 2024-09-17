## Angular Commit Convention

To maintain consistency in the commit history of the project, we follow the Angular Commit Convention. This convention helps in having clear, concise, and descriptive commit messages. Each commit consists of a required header and an optional body, separated by a blank line.

### Commit Header

The commit header follows the following format:

**`<type>(<scope>): <subject>`**


- `<type>`: Indicates the nature of the change. It can be one of the following types:
  - `feat`: Addition of a new feature.
  - `fix`: Fixing a bug or an error.
  - `docs`: Documentation-related changes.
  - `style`: Code style changes (indentation, spaces, etc.) that do not affect the meaning of the code.
  - `refactor`: Code changes that do not fix a bug or add a feature.
  - `test`: Addition or modification of tests.
  - `chore`: Project maintenance tasks, dependency updates, etc.
- `<scope>` (optional): Indicates the scope of the change. It can be a module name, file, or affected function.
- `<subject>`: Concise description of the change. It should be written in the imperative present tense, start with a capital letter, and not end with a period.

- Examples of commit headers:
  - feat(users): Add email login feature.
  - fix(api): Fix bug related to data encoding.
  - docs(readme): Update installation documentation.


### Commit Body

The commit body is used to provide additional details about the change. It can contain multiple paragraphs and should be written in a clear and explanatory manner. It may include information about the motivation behind the change, any issues encountered, or other relevant details.

Example of commit body:

Optional commit body, providing additional information about the changes made. It can explain why a certain approach was chosen or provide important technical details.


### Additional Conventions

- Commit messages should be written in English to ensure consistency for all contributors.

By following this commit convention, we can have a clear and informative history, making it easier to understand the changes made in the project.

### Issue Convention

For issues, we follow the following format (conventional commits):

**`<type>: <description>`**

- `<type>`: Indicates the nature of the issue. It can be one of the following types:
  - `FEAT`: Addition of a new feature.
  - `FIX`: Fixing a bug or an error.
  - `DOCS`: Documentation-related changes.
  - `STYLE`: Code style changes (indentation, spaces, etc.) that do not affect the meaning of the code.
  - `REFACTOR`: Code changes that do not fix a bug or add a feature.
  - `TEST`: Addition or modification of tests.
  - `CHORE`: Project maintenance tasks, dependency updates, etc.

- `<description>`: Concise description of the issue. It should be written in the imperative present tense, start with a capital letter, and not end with a period.
- Examples of issue descriptions:
  - FEAT: Add email login feature.
  - FIX: Fix bug related to data encoding.
  - DOCS: Update installation documentation.

By following this issue convention, we can have a clear and informative list of issues, making it easier to track and manage the project's progress.
