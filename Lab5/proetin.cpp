class ProteinSequence : public Sequence {
public:
    ProteinSequence(const string& d);
    ~ProteinSequence();

    void describe() const override;
    bool isValid() const override;
};
