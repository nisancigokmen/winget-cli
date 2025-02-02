// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "PackageCatalog.g.h"

namespace winrt::Microsoft::Management::Deployment::implementation
{
    struct PackageCatalog : PackageCatalogT<PackageCatalog>
    {
        PackageCatalog() = default;
        
#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
        void Initialize(
            winrt::Microsoft::Management::Deployment::PackageCatalogInfo info, 
            std::shared_ptr<const ::AppInstaller::Repository::ISource> source,
            bool isComposite);
#endif

        bool IsComposite();
        winrt::Microsoft::Management::Deployment::PackageCatalogInfo Info();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::Management::Deployment::FindPackagesResult> FindPackagesAsync(winrt::Microsoft::Management::Deployment::FindPackagesOptions options);
        winrt::Microsoft::Management::Deployment::FindPackagesResult FindPackages(winrt::Microsoft::Management::Deployment::FindPackagesOptions const& options);

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
    private:
        winrt::Microsoft::Management::Deployment::PackageCatalogInfo m_info{ nullptr };
        std::shared_ptr<const ::AppInstaller::Repository::ISource> m_source;
        bool m_isComposite = false;
#endif
    };
}
