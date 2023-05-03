// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_FONT_LANGUAGE_OVERRIDE_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_FONT_LANGUAGE_OVERRIDE_H_

#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class PLATFORM_EXPORT FontLanguageOverride {
 public:
  FontLanguageOverride() = default;
  explicit FontLanguageOverride(const AtomicString& language)
      : is_normal_(false), language_(language) {}

  bool operator==(const FontLanguageOverride& other) const {
    return is_normal_ == other.IsNormal() && language_ == other.Language();
  }
  bool operator!=(const FontLanguageOverride& other) const {
    return !operator==(other);
  }

  bool IsNormal() const { return is_normal_; }
  const AtomicString& Language() const { return language_; }

  String ToString() const { return {}; }

 private:
  bool is_normal_{true};
  AtomicString language_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_PLATFORM_FONTS_FONT_LANGUAGE_OVERRIDE_H_
