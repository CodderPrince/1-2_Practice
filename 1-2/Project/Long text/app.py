from flask import Flask, render_template, request
import subprocess
import os

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/result', methods=['POST'])
def result():
    # Directory to store uploaded files
    upload_dir = 'uploads'
    if not os.path.exists(upload_dir):
        os.makedirs(upload_dir)

    # Save uploaded files
    uploaded_files = {}
    for i in range(1, 7):
        key = f'document{i}'
        if key in request.files and request.files[key].filename != '':
            file = request.files[key]
            file_path = os.path.join(upload_dir, file.filename)
            file.save(file_path)
            uploaded_files[key] = file_path

    # Run the plagiarism checker C++ program
    result = subprocess.run(['./plagiarism.out'] + list(uploaded_files.values()), capture_output=True)

    # Get the output of the C++ program
    output = result.stdout.decode('utf-8')

    return render_template('result.html', output=output)

if __name__ == '__main__':
    app.run(debug=True)
