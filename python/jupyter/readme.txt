conda create -n myenv python=3.7
conda-env remove -n keras-ll

source activate keras-ll/source deactivate keras-ll
conda activate keras-ll/ conda deactivate

pip3 install --ignore-installed --upgrade tensorflow
# Python
import tensorflow as tf
hello = tf.constant('Hello, TensorFlow!')
sess = tf.Session()
print(sess.run(hello))
>>> Hello, Tensorflow!

pip install keras

pip install ipykernel

python3.7 -m ipykernel install --user --name=keras-ll

// anaconda archives
https://repo.continuum.io/archive/
