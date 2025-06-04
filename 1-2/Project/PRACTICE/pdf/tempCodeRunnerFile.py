  raise ValueError("Unsupported file format for document 1")

    if doc2_path.endswith('.pdf'):
        doc2_text = read_text_from_pdf(doc2_path)
    elif doc2_path.endswith('.docx'):
        doc2_text = read_text_from_docx(doc2_path)
    else:
        raise ValueError("Unsupported file format for document 2")

    # Calculate similarity
    similarity = calculate_similarity(doc1_text, doc2_text)

    # Check plagiarism
    if similarity >= threshold:
        print("Plagiarism detected! Similarity:", similarity)
    else:
        print("No plagiarism detected. Similarity:", similarity)

# Example usage:
doc1_path = "path/to/first/document.pdf"
doc2_path = "path/to/second/document.docx"
check_plagiarism(doc1_path, doc2_path)
