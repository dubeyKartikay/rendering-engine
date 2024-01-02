#ifndef TEST
#define TEST
class Test{
  public:
    virtual void Update(float deltaTime = 1.0f){}
    Test(){};
    virtual void Render() = 0;
    virtual void ImGuiRender() = 0;
    virtual ~Test(){};
    virtual const char * GetName(){return "Test";}
};
#endif // !TEST
