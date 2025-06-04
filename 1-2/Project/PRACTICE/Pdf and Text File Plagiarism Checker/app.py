"""Pdf, Document, Presentation, Text file and Directly text Plagiarism Checker"""
"""
Name:   Prince
Id:     12105007
Plagiarism: (total common lines /   total lines)    *   100 %

Availability:   
.pdf    to    .pdf
.docx   to    .docx
.pptx   to    .pptx
.txt    to    .txt
directly text       to      directly text

Note: Every file    to     Every file
"""




import os
from docx import Document
from PyPDF2 import PdfReader
from pptx import Presentation
def read_text_from_docx(file_path):
    doc = Document(file_path)
    text = ""
    for para in doc.paragraphs:
        text += para.text + "\n"
    return text.strip()


def read_text_from_pdf(file_path):
    with open(file_path, 'rb') as file:
        reader = PdfReader(file)
        text = ""
        for page in reader.pages:
            text += page.extract_text()
        return text.strip()


def read_text_from_pptx(file_path):
    prs = Presentation(file_path)
    text = ""
    for slide in prs.slides:
        for shape in slide.shapes:
            if hasattr(shape, "text"):
                text += shape.text + "\n"
    return text.strip()


def read_text_from_txt(file_path):
    with open(file_path, 'r') as file:
        text = file.read()
    return text.strip()


def calculate_similarity(text1, text2):
    lines1 = text1.split("\n")
    lines2 = text2.split("\n")
    total_lines = max(len(lines1), len(lines2))
    matching_lines = sum(1 for line1, line2 in zip(
        lines1, lines2) if line1.strip() == line2.strip())
    return (matching_lines / total_lines) * 100 if total_lines > 0 else 0


def main():
    file_extensions = ['.pdf', '.docx', '.pptx', '.txt']

    while True:
        print('\n')
        file1_path = input(
            "Enter the path or text for the first file: ").strip()
        print('\n')
        file2_path = input(
            "Enter the path or text for the second file: ").strip()

        if not file1_path and not file2_path:
            print("At least one file path or text input must be provided.")
            continue

        if file1_path:
            if os.path.exists(file1_path):
                if os.path.splitext(file1_path)[1] in file_extensions:
                    if file1_path.endswith('.pdf'):
                        text1 = read_text_from_pdf(file1_path)
                    elif file1_path.endswith('.docx'):
                        text1 = read_text_from_docx(file1_path)
                    elif file1_path.endswith('.pptx'):
                        text1 = read_text_from_pptx(file1_path)
                    elif file1_path.endswith('.txt'):
                        text1 = read_text_from_txt(file1_path)
                else:
                    text1 = file1_path
            else:
                text1 = file1_path
        else:
            text1 = ""

        if file2_path:
            if os.path.exists(file2_path):
                if os.path.splitext(file2_path)[1] in file_extensions:
                    if file2_path.endswith('.pdf'):
                        text2 = read_text_from_pdf(file2_path)
                    elif file2_path.endswith('.docx'):
                        text2 = read_text_from_docx(file2_path)
                    elif file2_path.endswith('.pptx'):
                        text2 = read_text_from_pptx(file2_path)
                    elif file2_path.endswith('.txt'):
                        text2 = read_text_from_txt(file2_path)
                else:
                    text2 = file2_path
            else:
                text2 = file2_path
        else:
            text2 = ""

        similarity = calculate_similarity(text1, text2)
        print('\n')
        print(f"Plagiarism: {similarity:.2f}%")
        print('\n')
        return similarity


if __name__ == "__main__":
    plagiarism_score = main()
