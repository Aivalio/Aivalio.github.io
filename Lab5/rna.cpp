bool RNASequence::isValid() const {
    for (char c : data)
        if (c!='A' && c!='C' && c!='G' && c!='U')
            return false;
    return true;
}
