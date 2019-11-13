FROM python:3.5

RUN pip install --no-cache-dir jupyterlab

RUN mkdir -p /code


WORKDIR /code

# install dependencies

RUN apt-get update; apt-get install -y libncurses5-dev libreadline-dev libgsl0-dev

# install neuron

ENV NRN_VER=7.7
ENV NRN=nrn-$NRN_VER
ENV VENV=/code/neuron
ENV PATH=$PATH:$VENV/bin

RUN wget http://www.neuron.yale.edu/ftp/neuron/versions/v$NRN_VER/$NRN.tar.gz
RUN tar xzf $NRN.tar.gz; rm $NRN.tar.gz

RUN mkdir $VENV; mkdir $VENV/build; mkdir $VENV/bin
RUN mkdir $NRN; \
    cd $NRN; \
    ./configure --with-nrnpython=python --disable-rx3d --without-iv --prefix=$VENV; \
    make; make install

RUN cd $VENV/bin; ln -s ../x86_64/bin/nrnivmodl

RUN cd $NRN/src/nrnpython; python setup.py install

RUN pip install numpy scipy pandas matplotlib requests jupyter
# Specify the default command to run
