FROM ubuntu: 18.04

RUN apt-get update && apt-get install --no-install-recommends -y\
	clang++ \
	make \
	graphviz \
	doxygen \
&& rm -rf /var/lib/apt/lists/*