class RNASequence : public Sequence {
public:
    RNASequence(const string& d);
    ~RNASequence();

    void describe() const override;
    bool isValid() const override;
};
