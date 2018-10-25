#ifndef RADIX_ENVIRONMENT_HPP
#define RADIX_ENVIRONMENT_HPP

#include <memory>
#include <radix/env/Config.hpp>

namespace radix {
  /** @brief Manage game environment
   *
   *  Manages the environment of the the game
   */

  class Environment {
  private:
    const std::shared_ptr<Config> config;
  public:
    Environment();
    std::shared_ptr<Config> getConfig();
    std::string getDataDir();
    void setDataDir(const std::string &string);
  };

} /* namespace radix */

#endif /* RADIX_ENVIRONMENT_HPP */
