FROM jupyter/scipy-notebook

USER root

RUN mkdir -p /code
RUN mkdir -p /config
RUN mkdir -p /notebooks
RUN mkdir -p /tmp

ENV PYTHONPATH="$PYTHONPATH:/code"

# install dependencies
RUN apt-get update; apt-get install -y libncurses5-dev libreadline-dev libgsl0-dev libx11-dev git bison flex automake libtool libxext-dev libncurses-dev python3-dev xfonts-100dpi cython3 libopenmpi-dev python3-scipy make zlib1g-dev

# install neuron
ENV NRN_VER=7.7
ENV NRN=nrn-$NRN_VER
ENV VENV=/neuron

RUN wget http://www.neuron.yale.edu/ftp/neuron/versions/v$NRN_VER/$NRN.tar.gz
RUN tar xzf $NRN.tar.gz; rm $NRN.tar.gz

RUN mkdir $VENV; mkdir $VENV/build; mkdir $VENV/bin
RUN mkdir $NRN; \
    cd $NRN; \
    ./configure --with-nrnpython=python --with-paranrn --enable-static=yes --disable-rx3d --without-iv --prefix=$VENV; \
    make; make install

# Make Skripts accessible
ENV PATH=$PATH:$VENV/x86_64/bin

RUN cd $NRN/src/nrnpython; python setup.py install


WORKDIR /tmp
ADD . /tmp
RUN pip install -r requirements.txt

WORKDIR /config
ADD jupyter_notebook_config.json /config/home/.jupyter/lab/
ADD jupyter_notebook_config.py /config/home/.jupyter/

# Specify the default command to run
