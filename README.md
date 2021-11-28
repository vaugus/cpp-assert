# cpp-assert

A very simple C++ embeddable assertion library.

## Test

- Run an alpine container with build-essentials:

```sh
docker build -t cpp-assert .

docker run -it -rm -v $(pwd):/work cpp-assert sh
```

- Compile an run tests:

```sh
make && ./main
```