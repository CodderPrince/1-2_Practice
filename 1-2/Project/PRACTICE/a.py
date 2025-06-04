"""Pdf and Text file Plagiarism Checker"""
"""
Name:   Prince
Id:     12105007
Plagiarism: (total common lines /   total lines)    *   100 %

Availability:   
.pdf    to    .pdf
.txt    to    .txt
.pdf    to    .txt
.txt    to    .pdf
directly text       to      directly text
"""




import difflib
import fitz  # PyMuPDF library for PDF handling
def extract_text(file_path):
    """Extracts text from a PDF or text file."""
    if file_path.endswith(".pdf"):
        doc = fitz.open(file_path)
        text = ""
        for page in doc:
            text += page.get_text()
    else:
        with open(file_path, "r") as f:
            text = f.read()
    return text


def calculate_similarity(text1, text2):
    """Calculates the similarity ratio between two texts in percentage, handling blank documents."""
    lines1 = text1.splitlines()
    lines2 = text2.splitlines()
    total_lines = max(len(lines1), len(lines2))
    total_common_lines = sum(1 for line1, line2 in zip(
        lines1, lines2) if line1 == line2)
    similarity_ratio = (total_common_lines / total_lines) * \
        100 if total_lines > 0 else 0
    return similarity_ratio


# Get user input
print("\n")
file1_path_or_text = input("Enter the path or text for the first file: ")
file2_path_or_text = input("Enter the path or text for the second file: ")

# Determine if user input is a file path or text
is_file1 = file1_path_or_text.endswith(
    ".pdf") or file1_path_or_text.endswith(".txt")
is_file2 = file2_path_or_text.endswith(
    ".pdf") or file2_path_or_text.endswith(".txt")

# Extract text from files or use input text directly
if is_file1:
    text1 = extract_text(file1_path_or_text)
else:
    text1 = file1_path_or_text

if is_file2:
    text2 = extract_text(file2_path_or_text)
else:
    text2 = file2_path_or_text

# Calculate and display similarity
similarity_ratio = calculate_similarity(text1, text2)
print(f"Plagiarism: {similarity_ratio:.2f}%")
print("\n")