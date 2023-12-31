#ifndef TEST
#define TEST
class Test{
  public:
    Test(){};
    virtual void Render() = 0;
    virtual void ImGuiRender() = 0;
    virtual ~Test(){};
};
#endif // !TEST
