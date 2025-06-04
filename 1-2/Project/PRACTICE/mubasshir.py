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
    matching_lines = sum(1 for line1, line2 in zip(lines1, lines2) if line1.strip() == line2.strip())
    return (matching_lines / total_lines) * 100 if total_lines > 0 else 0

def main():
    file_extensions = ['.pdf', '.docx', '.pptx', '.txt']

    while True:
        choice = input("Do you want to input text directly (Y/N)? ").strip().lower()

        if choice == 'y':
            text1 = input("Enter the first text: ").strip()
            text2 = input("Enter the second text: ").strip()
            similarity = calculate_similarity(text1, text2)
            print(f"Similarity: {similarity:.2f}%")
        elif choice == 'n':
            file1_path = input("Enter the path of the first file (leave blank for text input): ").strip()
            file2_path = input("Enter the path of the second file (leave blank for text input): ").strip()

            if not file1_path and not file2_path:
                print("At least one file path must be provided.")
                continue

            if file1_path:
                if not os.path.exists(file1_path):
                    print("File 1 does not exist.")
                    continue
                file1_ext = os.path.splitext(file1_path)[1]
                if file1_ext not in file_extensions:
                    print("Unsupported file format. Supported formats: PDF, DOCX, PPTX, TXT.")
                    continue
                if file1_ext == '.pdf':
                    text1 = read_text_from_pdf(file1_path)
                elif file1_ext == '.docx':
                    text1 = read_text_from_docx(file1_path)
                elif file1_ext == '.pptx':
                    text1 = read_text_from_pptx(file1_path)
                elif file1_ext == '.txt':
                    text1 = read_text_from_txt(file1_path)
            else:
                text1 = ""

            if file2_path:
                if not os.path.exists(file2_path):
                    print("File 2 does not exist.")
                    continue
                file2_ext = os.path.splitext(file2_path)[1]
                if file2_ext not in file_extensions:
                    print("Unsupported file format. Supported formats: PDF, DOCX, PPTX, TXT.")
                    continue
                if file2_ext == '.pdf':
                    text2 = read_text_from_pdf(file2_path)
                elif file2_ext == '.docx':
                    text2 = read_text_from_docx(file2_path)
                elif file2_ext == '.pptx':
                    text2 = read_text_from_pptx(file2_path)
                elif file2_ext == '.txt':
                    text2 = read_text_from_txt(file2_path)
            else:
                text2 = ""

            similarity = calculate_similarity(text1, text2)
            print(f"Similarity: {similarity:.2f}%")
        else:
            print("Invalid choice. Please enter 'Y' or 'N'.")
            continue

if __name__ == "__main__":
    main()
