// class.hpp
#ifndef XXXXX_HPP
#define XXXXX_HPP

namespace NAMESPACE {

/**
 * \class XXXXX
 * \ingroup Core
 *
 * \brief A brief description of the class.
 * 
 * A longer description of the class. Details and other information goes here.
 * It can span multiple lines.
 *
 * As well as have vertical spaces.
 */
template <typename T>
class XXXXX
{
public:
  typedef T* pointer; ///< A typedef for T*.

  static int value = 10; ///< A static int in the class. It equals 10.

public:
  /** Constructor for XXXXX. */
  XXXXX();

  /** Copy constructor for XXXXX */
  XXXXX(const XXXXX& x);

  /** Assignment operator for XXXXX */
  XXXXX& operator=(const XXXXX& x);

#if __cplusplus >= 201103L
  /** Move constructor for XXXXX */
  XXXXX(XXXXX&& x);

  /** Move assignment operator for XXXXX */
  XXXXX& operator=(XXXXX&& x);
#endif

  /** Destructor for XXXXX */
  ~XXXXX();

  /**
   * Get the value of the internal flag.
   *
   * \return The value of the internal flag of XXXXX.
   */
  bool get_flag() const;
  
  /**
   * Sets the flag of XXXXX.
   *
   * \param flag A boolean to set the flag.
   * \return None
   */
  void set_flag(bool flag = false);

  pointer get_pointer() const;
 
protected:

private:
  pointer ptr_;   ///< A pointer variable
  bool    flag_;  ///< A boolean flag variable
};

} // end namespace NAMESPACE

#endif // XXXXX_HPP
